# CLion Notes

## 多文件编译

1. 添加新文件/将已有文件移到工程文件夹
2. 在 `CMakeLists.txt` 中加入下列代码

````
file(GLOB SOURCES
*.h //*号对应具体的⽂件名
*.cpp
)
````

3. 将文件中的 `add_executable(main main.cpp)` 替换为 `add_executable(ChainList main.cpp ${SOURCE_FILES} ${SOURCES})` 