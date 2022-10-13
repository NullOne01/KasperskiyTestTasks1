# Задание для Касперского (C++)

<details>
<summary>Условие</summary>
Требуется реализовать утилиту, работающую из командной строки, для Linux или macOS, выполняющую сканирование файлов в директории, с целью нахождение в ней “подозрительных” (suspicious) файлов.
</details>

## Как запускать
Работал в CLion. Команда для CMake:
``
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" -S /Users/nullone/CLionProjects/KasperskiyTestTasks1/src -B /Users/nullone/CLionProjects/KasperskiyTestTasks1/src/cmake-build-debug
``
## Входные данные
Есть папка input_data. Это входные тестовые данные.
Скрипт generator.py может их генерировать.

## Пару слов об оптимизациях
В задании говорилось про "утилизацию".
Как я понял, лучшая оптимизация здесь - это добавление потоков.
Однако, добавлять потоки для чтения файлов - смысла не имеет (они будут друг друга блочить).
