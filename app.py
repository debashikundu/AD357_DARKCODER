from flask import Flask, request, jsonify, render_template

app = Flask(__name__)

def upload_file():
    file1 = request.form.get('inputfile')
    file2 = request.form.get('inputfile')
    cursor.execute("""INSERT INTO `file` (`file1`,`file2`) VALUES
    ('{}','{}')""".format(file1, file2))
    conn.commit()

    model = pickle.load(open('model.pkl', 'wb'))
    npimg = compr(file1, file2)

    flood_img1 = cv2.imread(img1, 0)
    flood_img1 = cv2.resize(flood_img1, (169, 225))
    otimg = np.array(flood_img1).flatten().reshape(169, 225)
    return render_template("uploaded.html", otimg=outputimg, pre=pre)

if __name__=="__main__":
    app.run(debug=True)
