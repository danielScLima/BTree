BTree
====================

This repository has a project with the implementation of a BTree.

It is written in C++.

The code of the BTree is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the BTree (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the BTree, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Search;](#markdown-header-emphasis)	
	* [Remove.](#markdown-header-emphasis)
	
- - -

Sample images: 
====================

![Alt text](images/sample.png)


Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/guisample.png)



Insertion steps: 
====================

## Initial:

![Alt text](images/insertion/0.png)

## Inserting 50:

![Alt text](images/insertion/1.png)

## Inserting 40:

![Alt text](images/insertion/2.png)

## Inserting 60:

![Alt text](images/insertion/3.png)

## Inserting 70:

![Alt text](images/insertion/4.png)

## Inserting 80:

![Alt text](images/insertion/5.png)

## Inserting 90:

![Alt text](images/insertion/6.png)

## Inserting 45:

![Alt text](images/insertion/7.png)

## Inserting 55:

![Alt text](images/insertion/8.png)

## Inserting 85:

![Alt text](images/insertion/9.png)

## Inserting 75:

![Alt text](images/insertion/10.png)

## Inserting 65:

![Alt text](images/insertion/11.png)

## Inserting 35:

![Alt text](images/insertion/12.png)

## Inserting 30:

![Alt text](images/insertion/13.png)

## Inserting 20:

![Alt text](images/insertion/14.png)

## Inserting 21:

![Alt text](images/insertion/15.png)

## Inserting 22:

![Alt text](images/insertion/16.png)

## Inserting 23:

![Alt text](images/insertion/17.png)

## Inserting 25:

![Alt text](images/insertion/18.png)

Removing samples (mixed with insertions): 
====================

## Initial:

![Alt text](images/remove/0.png)

## Removing 90:

![Alt text](images/remove/1.png)

## Removing 85:

![Alt text](images/remove/2.png)

## Inserting 26:

![Alt text](images/remove/3I.png)

## Removing 21:

![Alt text](images/remove/4.png)

## Inserting 56:

![Alt text](images/remove/5I.png)

## Removing 60:

![Alt text](images/remove/6.png)