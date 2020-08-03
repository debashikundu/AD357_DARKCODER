#!/usr/bin/env python
# coding: utf-8

# In[20]:


import pandas as pd
import numpy as np
import sklearn as sk
from sklearn import metrics, datasets
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans


# In[21]:


df = pd.read_csv('austin_final.csv')
df


# In[22]:


df.isnull().sum()


# In[23]:



x = df.drop(['PrecipitationSumInches'], axis=1)

y = df.PrecipitationSumInches


# In[24]:


def refar(ag):
  if (ag<0.001):
    return 0
  elif (ag>=0.001 and ag<0.1):
    return 1
  elif (ag>=0.1 and ag<1.2):
    return 2
  else :
    return 3


# In[25]:


for i in range(1305):
  y[i] = refar(y[i])


# In[26]:


y


# In[27]:


from sklearn.model_selection import train_test_split


# In[28]:


x_train, x_test, y_train, y_test = train_test_split (x,y,test_size=0.2,random_state=13)


# In[29]:


model = LogisticRegression(multi_class='ovr', solver='liblinear')
model.fit(x_train,y_train)


# In[30]:


model.score(x_test,y_test)


# In[19]:


kmeans = KMeans(n_clusters=3) # You want cluster the passenger records into 2: Survived or Not survived
kmeans.fit(df)


# In[ ]:





# In[35]:


df


# In[ ]:





# In[ ]:




