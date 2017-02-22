import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        posfile = open(positives, "r")
        negfile = open(negatives, "r")
        posStr = str(posfile.read())
        negStr = str(negfile.read())
        checker = False
        posit = ""
        negat = ""
        for i in posStr:
            if checker == True:
                if i == '\n':
                    checker = False
                continue
            if ";" in i:
                checker = True
            else:
                posit += i
        
        for i in negStr:
            if checker == True:
                if i == '\n':
                    checker = False
                continue
            if ";" in i:
                checker = True
            else:
                negat += i
        self.positives = posit.splitlines()
        self.negatives = negat.splitlines()
        
        posfile.close()
        negfile.close()
        # TODO

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        text = text.lower()
        if text in self.positives:
            return 1
        elif text in self.negatives:
            return -1
        else:
            return 0
        # TODO
        return 0
