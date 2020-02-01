from flask import Flask, render_template, request

app=Flask(__name__)

@app.route('/')

def index():
    return render_template('index.html')

@app.route('/', methods=['POST'])
def getvalue():
    name=request.form['name']
    age=request.form['age']
    dob=request.form['dateofbirth']
    return render_template('pass.html', n=name, age=age, dob=dob)
 
if __name__=='__main__':
    app.run(debug=True)
    