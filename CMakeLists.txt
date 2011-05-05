cmake_minimum_required(VERSION 2.6)

PROJECT(VectorImageFiltering)

FIND_PACKAGE(ITK REQUIRED)
INCLUDE(${ITK_USE_FILE})

ADD_EXECUTABLE(VectorImageFiltering VectorImageFiltering.cpp)
TARGET_LINK_LIBRARIES(VectorImageFiltering ${ITK_LIBRARIES})

