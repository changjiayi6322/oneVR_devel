////////////////////////////////////////////////////////////////////////////////
//
// Program: Radial Stitcher
// Author: Felix Tsao
// Contact: hello@felixtsao.com
//
// Summary:
//
//     Simple panorama image/video stitcher. Assumes input frames are taken
//     from radially symmetric viewpoints i.e. after projection, stitching
//     challenge is reduced to recovering angles between cameras
//     i.e. translation in the video plane space.
//
//     Developed using OpenCV 3.1.0 release and Ubuntu 16.04
//
//     Written using feature descriptors from OpenCV. This code is free to be
//     copied and modified and adheres to the same OpenCV license below.
//
//
////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this
//  license. If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote
//     products derived from this software without specific prior written
//     permission.
//
// This software is provided by the copyright holders and contributors "as is"
// and any express or implied warranties, including, but not limited to, the
// implied warranties of merchantability and fitness for a particular purpose
// are disclaimed. In no event shall the Intel Corporation or contributors be
// liable for any direct, indirect, incidental, special, exemplary, or
// consequential damages (including, but not limited to, procurement of
// substitute goods or services; loss of use, data, or profits; or business
// interruption) however caused and on any theory of liability, whether in
// contract, strict liability, or tort (including negligence or otherwise)
// arising in any way out of the use of this software, even if advised of the
// possibility of such damage.
//
////////////////////////////////////////////////////////////////////////////////

// Standard
#include <iostream>

// Radial Stitcher
#include "RadialStitcher.hpp"

////////////////////////////////////////////////////////////////////////////////


// How to use this program
// -----------------------------------------------------------------------------
int usage(){
    std::cout << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "    ./radStitch <image1> <image2> ... <imageN>" << std::endl;
    std::cout << std::endl;
    std::cout << "Constraints:" << std::endl;
    std::cout << "    1) Stitcher assumes inputs are taken from radially symmetric viewpoints relative to a single optical center" << std::endl;
    std::cout << "    2) Specified adjacent images must overlap and share common features" << std::endl;
    std::cout << std::endl;
    exit(1);
};


// Panorama stitcher program
// -----------------------------------------------------------------------------
int main(int argc, char ** argv) {

    if(argc < 3) usage(); // Need at least 2 images
    int numImages = argc - 1;

    // Load in images to stitcher
    RadialStitcher * rs = new RadialStitcher(numImages, argv);

    // Try stitching images
    if(rs->Stitch()) std::cout << "Stitch failed." << std::endl;;

    delete rs;

    return 0;

}
