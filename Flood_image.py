#!/usr/bin/env python
# coding: utf-8

#   

# In[4]:


import os
import numpy as np
import cv2
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
import matplotlib.pyplot as plt 
 


# In[5]:


dir = 'C:\\Users\\ijazu\\Desktop\\ArcGIS\\imgpro'
 
categories = ['Flood','Not-flood']

data =[]


# In[6]:


for category in categories:
    path = os.path.join(dir,category)
    label= categories.index(category)
    
    for img in os.listdir(path):
        imgpath = os.path.join(path,img)
        flood_img = cv2.imread(imgpath,0)
        flood_img = cv2.resize(flood_img,(169,225))
        image = np.array(flood_img).flatten()
        
        data.append([image,label])


# In[7]:


print(len(data))


# In[8]:



features = []
labels = []


# In[9]:


for feature ,label in data:
    features.append(feature)
    labels.append(label)


# In[10]:


x_train, x_test, y_train, y_test = train_test_split(features, labels, test_size = (10/64),random_state=19)#19


# In[11]:


model =SVC(kernel='poly',gamma='auto')
model.fit(x_train,y_train)


# In[12]:


model.score(x_test,y_test)


# In[13]:


model.predict(x_test)


# In[14]:


y_test


# In[15]:

x = numpy.arange(0, 1, 0.05)
y = numpy.power(x, 2)

fig = 'C:\\Users\\ijazu\\Desktop\\ArcGIS\\imgpro\\2.jpg' 
ax = fig.gca()
ax.set_xticks(numpy.arange(0, 1, 0.1))
ax.set_yticks(numpy.arange(0, 1., 0.1))
plt.scatter(x, y)
plt.grid()
plt.show()



# In[25]:

import pickle
pickle.dump(model, open('model.pkl','wb'))




# In[26]:


kmeans = KMeans(n_clusters=3) # You want cluster the passenger records into 2: Survived or Not survived
kmeans.fit(df)

# In[ ]:




