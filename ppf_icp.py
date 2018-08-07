#!/usr/bin/python

import cv2
import numpy as np

model=cv2.ppf_match_3d.loadPLYSimple('model-low.ply',0) #No nominal
print model.shape

scene=cv2.ppf_match_3d.loadPLYSimple('scene-high.ply',0) #No nominal

icp = cv2.ppf_match_3d_ICP(100,0.2,2.0,8)

pose=np.array([
  [1,0,0,0],
  [0,1,0,14],
  [0,0,1,0],
  [0,0,0,1]
])

modela=cv2.ppf_match_3d.transformPCPose(model,pose)

ret,residu,posea=icp.registerModelToScene(modela,scene)

print "pose",posea
