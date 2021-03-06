# CMake Template

> Template for projects based on modern CMake practices.
  
Components:  
├── app  
│   ├── CMakeLists.txt      *****  https://github.com/SachinGodse/cpp/blob/master/app/CMakeLists.txt  
│   └── main.cpp  
├── azure-pipelines.yml  
├── CMakeLists.txt          *****  https://github.com/SachinGodse/cpp/blob/master/CMakeLists.txt  
├── libs  
│   ├── CMakeLists.txt      *****  https://github.com/SachinGodse/cpp/blob/master/libs/CMakeLists.txt  
│   └── lib1  
│       ├── CMakeLists.txt  *****  https://github.com/SachinGodse/cpp/blob/master/libs/lib1/CMakeLists.txt  
│       ├── include  
│       │   └── lib1  
│       │       └── lib1-pub-header.h  
│       ├── lib1-priv-header.h  
│       ├── lib1-priv-impl.cpp  
│       ├── lib1-pub-impl.cpp  
│       └── tests  
│           ├── CMakeLists.txt  ***** https://github.com/SachinGodse/cpp/blob/master/libs/lib1/tests/CMakeLists.txt  
│           └── main.cpp  
├── LICENSE  
├── Makefile  
└── README.md  
  

See [How to Use Modern CMake for an App + Lib Project](https://rvarago.github.io/2018/08/20/how-to-use-modern-cmake-for-an-app-p-lib-project.html) for more information.

## Usage

Create the `build` directory and configure the build system:

```bash
cmake -B build # Or 
cmake -D BUILD_TESTING=OFF -B build  #  to skip tests. 
```

Build the project:

```bash
cmake --build build
```

Inspect the `build` directory to find the application and the tests.

Optionally, run the tests with `ctest` by typing:

```bash
cmake -E chdir build ctest
```
