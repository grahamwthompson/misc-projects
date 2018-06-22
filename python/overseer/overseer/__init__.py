# Main Flask application for overseer
# 1: initialize flask application, models, etc
# 2: import settings with scheduler and ssh login information
# 3: import our log fetcher and parser and set to run on configured scheduler
from flask import Flask
from paramiko import client

app = Flask(__name__)

import overseer.views

#from fetch import fetchLogsPass
#fetchLogsPass(last=None, server=u"www.witiko.co", user=u"root", password=u"sometimesiwonderaboutentropy")
