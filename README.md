MedicalTile
===========
Description
----------------
MedicalTile is an open source software for 2D and 3D medical image visualization and processing. 
It's base on Qt and ITK. It can only work on WIN32 platform for now.

Feature
---------------
* Import CT or MR image folders.
* Display 3D image as slices.
* Image processing algorithms including morphological algorithms, watershed algorithm, registration and etc.
* Data visualization.
* Extremely extensible. Any one can add plugins as DLL to it without recompiling the whole project. 

How to compile?
---------------
####First, download the 3rd party libraries.
* Download ITK 4.1.0 from [ITK](http://www.itk.org/ITK/resources/legacy_releases.html)
* Download Qt >= 4.8.1 (I use 4.8.1 for this project, and Qt 4.8.5 also works fine) from [Qt](http://download.qt-project.org/archive/qt/4.8/)
* Download DCMTK3.6 from [DCMTK](http://dicom.offis.de/dcmtk.php.en)

####Second, add 3rd pary libraries and compile. 
I use Visual studio 2010 to compile this project, have never tried any other version of Visual Studio.
Install Qt add-in for visual studio. You can find it in the downloaded Qt package.
Add headers and libraries to visual studio.
Then, open the sln file in your visual studio and click build!

