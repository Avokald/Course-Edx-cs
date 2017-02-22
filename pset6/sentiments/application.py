from flask import Flask, redirect, render_template, request, url_for

import helpers
from analyzer import Analyzer
import nltk
import os 
import sys


app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "").lstrip("@")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name)
    if tweets == None:
        return "No data"
    
    # TODO
    positive, negative, neutral = 0.0, 0.0, 0.0
    tokenizer = nltk.TweetTokenizer()
    
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")
    
    analyzer = Analyzer(positives, negatives)
    
    for i in tweets:
        summ = 0
        tweetSplit = tokenizer.tokenize(i)
        for j in tweetSplit:
            summ += analyzer.analyze(j)
        if summ > 0:
            positive += 1
        elif summ < 0:
            negative += 1
        else:
            neutral += 1
    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
