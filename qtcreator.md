# import existing C++ projects to QtCreator

## Let's assume the project's name is proj.

 1. touch an empty file named *proj.config*.
 2. create file *proj.creator* with following contents
> [General]
 3. create file *proj.files* with all the file names in the project, usually all the .h and .cpp files.
 4. create file *proj.includes* with, usually, all the directories under the project.
 5. open *proj.creator* with QtCreator, i.e., type 
> `qtcreator proj.creator`
 6. configure build & run commands in the **Projects** tab, e.g., `make all` for build, and `a.out` for run.
 7. edit, build and run within the IDE.