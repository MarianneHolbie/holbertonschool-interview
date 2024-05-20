#!/usr/bin/python3
"""
    Printed sorted count of given keywords en title hot articles
"""
from collections import Counter
import requests

BASE_URL = 'https://www.reddit.com/r/{}/hot.json'


def count_words(subreddit, word_list, after=None, counts=None):
    """
        recursiv function that queries Reddit API, parses the title
        of all hot articles and prints a sorted count of given keywords
    :param subreddit:subreddit to query
    :param word_list: list of keywords to count
    :param after: fullname of an item in the listing
    :param counts: counter
    :return: None
    """
    # intiailize counter if not given
    if counts is None:
        counts = Counter()

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

    # count occurrences of words in title
    for post in posts:
        title = post['data']['title'].lower().split()
        for word in title:
            cleaned_word = ''.join(char for char in word if char.isalnum())
            if cleaned_word in word_list:
                counts[cleaned_word] += 1

    # recursiv call
    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_counts = sorted(counts.items(),
                               key=lambda item: (-item[1], item[0]))
        for word, count in sorted_counts:
            if count > 0:
                print(f'{word}: {count}')
