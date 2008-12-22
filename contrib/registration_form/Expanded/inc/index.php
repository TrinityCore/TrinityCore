<?php
session_start();

/* 
AnimCaptcha v1.3 >> 6-13-07

This Animated Gif Captcha system is brought to you courtesy of ...
josh@betteradv.com                                    ==> Josh Storz
http://www.querythe.net/Animated-Gif-Captcha/         ==> Download Current Version

OOP (PHP 4 & 5) Interface by ...
krakjoe@krakjoe.info                                  ==> J Watkins

The GIFEncoder class was written by ...
http://gifs.hu                                        ==>  László Zsidi
http://www.phpclasses.org/browse/package/3163.html    ==>  Download Current Version 

This file is part of QueryThe.Net's AnimatedCaptcha Package.

    QueryThe.Net's AnimatedCaptcha is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    QueryThe.Net's AnimatedCaptcha is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with QueryThe.Net's AnimatedCaptcha; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

include "GIFEncoder.class.php";

function add_random_frames($frame)  {
// random number & elapsed time of frames to *hopefully* make a cracker's life tougher
    
    global $frames ;
    global $time ;
    
    $i = 0;
    $loop = rand(6, 14);  // total number of frames in loop loop
        
    while ($i < $loop)
      {
        $frames [ ] = "frames/$frame.gif"; // use the solve frame so that the human eye cannot see a flicker
        $time [ ] = rand(15, 25); // 5 * 20 = 1 second so the delay is never too terribly long
        $i ++ ;
      }
}

// get random numbers & operator and make sure the answer is >= 0
    $k = 0 ;
    while($k == 0)
      {
        $rand1 = rand(1, 9);  // 1st number (1-9)
        $rand3 = rand(1, 9);  // 2nd number (1-9)
        $rand2 = rand(0, 2);  // operator (-,+,*)
        
        if (($rand2 != 0) || ($rand3 < $rand1)) $k = 1 ;
      }

// set sessions for numbers, operator & answer.  Only $_SESSION['answer'] is necessary.  Others are for displaying full equation if you desire.
    $_SESSION['r1'] = $rand1 ;
    $_SESSION['r3'] = $rand3 ;
    
    if ($rand2 == 0)      {$_SESSION['r2'] = " - " ; $_SESSION['answer'] = $rand1 - $rand3 ; $frame_operator = "minus" ;}
    elseif ($rand2 == 1)  {$_SESSION['r2'] = " + " ; $_SESSION['answer'] = $rand1 + $rand3 ; $frame_operator = "plus" ;}
    else                  {$_SESSION['r2'] = " * " ; $_SESSION['answer'] = $rand1 * $rand3 ; $frame_operator = "times" ;}

// build the frame images and elapsed time to show in 2 arrays
    $frames [ ] = "frames/solve.gif" ;  // Intro message " Prove you are human ... "
    $time [ ] = 140;  
    add_random_frames('solve') ;
          
  // set 1st random number 
    $frames [ ] = "frames/" .$rand1. ".gif";  // 1st number (0-9)
    $time [ ] = 35;
    add_random_frames($rand1) ;
    
  // set frame for operator
    $frames [ ] = "frames/" .$frame_operator. ".gif" ;
    $time [ ] = 60;
    add_random_frames($frame_operator) ;
    
  // set 2nd random number
    $frames [ ] = "frames/" .$rand3. ".gif";  // 2nd number (0-9)
    $time [ ] = 35;
    add_random_frames($rand3) ;

    
  // set final frame for equals
    $frames [ ] = "frames/equals.gif" ; // Ending message " equals    = "
    $time [ ] = 140;  // equals frame time (100 = 1 second)
    add_random_frames('equals') ;

// encode the gif using the class to avoid gd dependencies
    $gif = new GIFEncoder	(
    							$frames, // frames array
    							$time, // elapsed time array
    							0, // loops (0 = infinite)
    							2, // disposal
    							0, 0, 0, // rgb of transparency
    							"url" // source type
    		);

// display the image
Header ( 'Content-type:image/gif' );
echo	$gif->GetAnimation ( );

?>
