#!/usr/bin/python3
"""
    Printed sorted count of given keywords en title hot articles
"""
import requests
from collections import Counter

BASE_URL = 'https://www.reddit.com/r/{}/hot.json'


def count_words(subreddit, word_list):
    """
        recursiv function that queries Reddit API, parses the title of all hot articles
        and prints a sorted count of given keywords
    :param subreddit:subreddit to query
    :param word_list: list of keywords to count
    :return: None
    """

    def recursiv_count(subreddit, word_list, counts, after=None ):
        """
            recursiv counter

        :param subreddit: subreddit keyword
        :param word_list: list of word
        :param counts: counter
        :param after: fullname of an item in the listing to use as anchor point
            of slice
        :return: None
        """

        # parameter for the HTTP request
        headers = {'User-agent': 'Holberton'}
        params = {'limit': 100}
        # add after to params
        if after:
            params['after'] = after

        # get response of request
        response = requests.get(BASE_URL.format(subreddit),
                                headers=headers,
                                params=params,
                                allow_redirects=False)

        if response.status_code != 200:
            return None

        data = response.json().get('data', {})
        posts = data.get('children', [])
        after = data.get('after', None)

        for post in posts:
            title = post['data']['title'].lower().split()
            for word in title:
                cleaned_word = ''.join(char for char in word if char.isalnum())
                if cleaned_word in word_list:
                    counts[cleaned_word] += 1

        if after:
            recursiv_count(subreddit, word_list, counts, after)
        else:
            sorted_counts = sorted(counts.items(), key=lambda item: (-item[1], item[0]))
            for word, count in sorted_counts:
                if count > 0:
                    print(f'{word}: {count}')

    word_list = [word.lower() for word in word_list]
    counts = Counter()
    recursiv_count(subreddit, word_list, counts)