cmake_minimum_required(VERSION 3.3)
project(FolderSystem_master)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ClonAble.cpp
    ClonAble.h
    Dir.cpp
    Dir.h
    DirBuilder.cpp
    DirBuilder.h
    File.cpp
    File.h
    FileBuilder.cpp
    FileBuilder.h
    main.cpp
    Menu.cpp
    Menu.h
    ObjDirector.cpp
    ObjDirector.h
    Object.cpp
    Object.h
    ObjectBuilder.cpp
    ObjectBuilder.h
    Root.cpp
    Root.h)

add_executable(FolderSystem_master ${SOURCE_FILES})