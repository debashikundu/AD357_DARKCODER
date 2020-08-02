from flask import Flask, request, jsonify, render_template

app = Flask(__name__)


@app.route('/')
def home(latitude, longitude):
    return '<h1>you dont have permission to use this app without any value</h1>'


@app.route('/formapp/<latitude>/<longitude>')
def index(latitude, longitude):

    geocode = [latitude, longitude]

    return render_template('getloc.html', geocode=geocode)

if __name__=="__main__":
    app.run(debug=True)
