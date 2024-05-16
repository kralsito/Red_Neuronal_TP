from pip import tweepy

consumer_key = 'TU_CONSUMER_KEY'
consumer_secret = 'TU_CONSUMER_SECRET'
access_token = 'TU_ACCESS_TOKEN'
access_token_secret = 'TU_ACCESS_TOKEN_SECRET'

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)

nombre_usuario = 'usuario_ejemplo'
tweets_usuario = api.user_timeline(screen_name=nombre_usuario, count=10)
for tweet in tweets_usuario:
    print(tweet.text)
