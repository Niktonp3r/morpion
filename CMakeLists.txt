cmake_minimum_required(VERSION 3.10)

# Définir une variable pour le nom du projet
set(PROJECT_NAME "LOU_MORPION")

# Nom du projet
project(${PROJECT_NAME})

# Répertoire des fichiers sources
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Chercher récursivement tous les fichiers .cpp dans le dossier src
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

# Ajouter les fichiers sources au projet
add_executable(${PROJECT_NAME} ${SOURCES})

# Options de compilation (par exemple : C++17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# Inclure les répertoires d'en-têtes (si besoin)
include_directories(${SRC_DIR})
