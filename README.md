# ofxOpenCvDnnObjectDetection

![sample_images/result_sample01.gif](sample_images/result_sample01.gif)
## Description
ofxOpenCvDnnObjectDetection is an addon for openframeworks(version.0.11.0).

I created this addon for beginers or learner who are going to try object detection with Yolo, SSD and R-CNN on OF. Latest oF includes opencv(version4) as a default opencv library, so you can run dnn object detection with ofxOpenCv. 

## Usage
See Examples for more details

### single_image
![single_image screenshot](/sample_images/screenshot.png)
Detection example for single image.

### camera
Realtime Detection example for webcam video & video

### annotation
![annotation screenshot](/sample_images/annotation.png)
My annotation software to export a yolo format. It enables you to annotate image, video, camera. I'm preparing the manual to use it.... not yet.

## Install and Run a single_image detection example.
### 1. Clone ofxOpenCvDnnObjectDetection to your of/addon directory
    $ git clone https://github.com/TetsuakiBaba/ofxOpenCvDnnObjectDetection.git



## Getting Started with Examples/single_image.
### 1. Download models
    $ sh getWeights.sh
### 2. Open a project generator and import Example/single_image. Then click the update button.
![projectgenerator](sample_images/projectgenerator.png)
### 3. Open the project with IDE and just run.

## Sample result images
![sample_images/result_sample02.gif](sample_images/result_sample02.gif)
## Compatibility
- only macOS ( tested on Catalina 10.15)
- linux 64 (arch based manjaro linux419 tested)
- oF version: 0.11.0

## Licence
- Source Code: [MIT](https://opensource.org/licenses/MIT)
- Videos
  - [Video by Pixabay from Pexels](https://www.pexels.com/video/cows-eating-856065/)
  - [Video by Pixabay from Pexels](https://www.pexels.com/video/mercedes-c-class-854710/)

## Author
[TetsuakiBaba](https://github.com/TetsuakiBaba)

## Reference
1. Model Zoo on OpenCV DNN Module README page: https://github.com/opencv/opencv/blob/master/samples/dnn/README.md
2. How to implement OpenCV Yolo on Openframeworks: https://qiita.com/buchayaty/items/4020100f531c07418f38
