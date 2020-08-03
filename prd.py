import pickle
import cv2
import numpy as np
import pickle
import matplotlib.pyplot as plt
import matplotlib.ticker as plticker
from PIL import Image

model = pickle.load(open('model.pkl', 'rb'))
categories = ['Flood', 'Not-flood']

img1 = 'C:\\Users\\ijazu\\Desktop\\ArcGIS\\imgpro\\2.jpg' 

flood_img1 = cv2.imread(img1, 0) 
flood_img1 = cv2.resize(flood_img1, (169, 225))  
img2 = np.array(flood_img1).flatten()  


image = Image.open(img1)



fig=plt.figure(figsize=(float(image.size[0])/my_dpi,float(image.size[1])/my_dpi),dpi=my_dpi)
ax=fig.add_subplot(111)


fig.subplots_adjust(left=0,right=1,bottom=0,top=1)

myInterval=300.
loc = plticker.MultipleLocator(base=myInterval)
ax.xaxis.set_major_locator(loc)
ax.yaxis.set_major_locator(loc)

ax.grid(which='major', axis='both', linestyle='-', color='y')

ax.imshow(image)

nx=abs(int(float(ax.get_xlim()[1]-ax.get_xlim()[0])/float(myInterval)))
ny=abs(int(float(ax.get_ylim()[1]-ax.get_ylim()[0])/float(myInterval)))




fig.savefig('3(1).jpg')

pickle.dump(fig, open('model.pkl','wb'))

prediction = categories[int(model.predict([img2]))]  # predicting the input
print(prediction)
