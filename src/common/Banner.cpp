/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Banner.h"
#include "GitRevision.h"
#include "StringFormat.h"

void Trinity::Banner::Show(char const* applicationName, void(*log)(char const* text), void(*logExtraInfo)())
{
    log(Trinity::StringFormat("{} ({})", GitRevision::GetFullVersion(), applicationName).c_str());  //新的更新会让此处显示生产版本,而不是以前固定的值
    log(R"(<Ctrl-C> to stop.)");
    
    //log(R"( ______                       __)");
    //log(R"(/\__  _\       __          __/\ \__)");
    //log(R"(\/_/\ \/ _ __ /\_\    ___ /\_\ \, _\  __  __)");
    //log(R"(   \ \ \/\`'__\/\ \ /' _ `\/\ \ \ \/ /\ \/\ \)");
    //log(R"(    \ \ \ \ \/ \ \ \/\ \/\ \ \ \ \ \_\ \ \_\ \)");
    //log(R"(     \ \_\ \_\  \ \_\ \_\ \_\ \_\ \__\\/`____ \)");
    //log(R"(      \/_/\/_/   \/_/\/_/\/_/\/_/\/__/ `/___/> \)");
    //log(R"(                                 C O R E  /\___/)");
    //log(R"(http://TrinityCore.org                    \/__/)");
    //log(R"(XGirl Self Development and improvement Edition.)");
    //log(R"(小女孩自研版.)");*/  //原先到这里结束
    //log(R"(                      ...=..^..*oo==.*.^/]/\]/]]......^o**....=.......);
    //log(R"(                  ...=..^..,OOOOOOOOOOOOOOOOOOO\`.^o*.....=.......);
    //log(R"(                  ...=.]O@@@OOOOOOOO@@@@@@OOOOOOO@@@@@O\`.=.......);
    //log(R"(                  ..,O@@OOOOOOO@@@@@@@OOO@@@@`/OOOOOO@@@@@O.......);
    //log(R"(                  ,@@@@@@@@O@@@@OOOOOOOOO@OOOOOOOO@@OOOOO@@@\.....);
    //log(R"(            .....O@@@O@O@OOOOO@O@@OOOOO@OOOOOOOOOO@OO@@OOOOOOO\...);
    //log(R"(               ,@@@@OO@O@OOOOO@@OOO@@@OOOOOOOOOOOO@@O@@@OOOOOOOO..);
    //log(R"(            ..,@@@@@OOO@@@OOOOOO@OOOO@@OOOOOOOOOO@@@O@@@@@OO@OOOO.);
    //log(R"(            .,@OO@OOOOOO@OOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@\/OO/=OOO.);
    //log(R"(            .O[O@^OOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOO@@@O....\OO@^);
    //log(R"(            =@OO^ \@OOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@^].,\OO@^);
    //log(R"(            \@OO  ,O@OOOO]OOOOOOOOOOOOOOOOOOOOOOOO/,O[]@O^.. .\OO^);
    //log(R"(            O@@O    OO@OOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@^. ..`,/O@/.);
    //log(R"(            ,@@O./[[ ,\O\,O@OOOOOOOO@OOOOOOOOOOOOOOOO@@O^.... ,[..);
    //log(R"(            ..O@^ ..].   \\`[OO@OOOOOOOOOOOO@OOOOOOO@@OO^..` .,...);
    //log(R"(            ..,@O=/OOOOO    ,[. ,[\O]]OOOOOO[[[OOOOOO@O@`[^.`\O\..);
    //log(R"(            .../O^ \OOOOO          OOOOOOOO OO. =[ ,O@@@O^`.]^..[O);
    //log(R"(            ..,.=^ .\OOO/           =OOOOOOOOO  .    @@@\OOOOO  ..);
    //log(R"(            **. .^                   =OOOOOO`       /@OOOOOOOO   .);
    //log(R"(                ..                                ,OO@@OOOOOO^....);
    //log(R"(                                             ,OO@@@@@OOOOOOOO     );
    //log(R"(                                           .OOO@@@@@@@@@OOO/......);
    //log(R"(                    ....                ....=OOO@@@@@O@O\O@Ooooooo);
    //log(R"(                    ......,`.   ....       .]OOOOO@@@@@OOO/       );
    //log(R"(                    .   ...,/.        ]/OOOOOOOOOOOOOO/.*..       );
    //log(R"(                        .ooO.     ]OoooooOOOOOOOOO`..^. *..       );
    //log(R"(XGirl Self Development and improvement Edition.)");
    //log(R"(XCore,小女孩自研版.)");
    




    //            ......     .....              .....
    //       /@@@@@@@@@@@O=@@@@@@@@@`      .]@@@@@@@@@@@@@@`    ./@@@@@@`                    .]/@@@@@O.
    //       \@@@@@@@@@@@`.\@@@@@/[[.    ,@@@@@@@@@@@@@@@@@@^  .@@@@@@@@`                  .O@@@@@@@@O
    //          \@@@@@@@@\/@@@@`       ./@@@@@@/.    .\@@@@@^   .,[[[. .          .     .   .,@@@@@@@^
    //           .@@@@@@@@@@@/         /@@@@@@@.       .\@@/.   .]O@@@@@O  .,/@@@@@@.=@@@@@`  =@@@@@@^
    //             ,@@@@@@@@@`        =@@@@@@@\                =@@@@@@@@O  \@@@@@@@@@@@@@@@O  =@@@@@@^
    //              .@@@@@@@@@\.      =@@@@@@@@.   ,O@@@@@@@@@`  =@@@@@@O   .@@@@@@@/@@@@@@`  =@@@@@@^
    //             ,@@@@@@@@@@@@`     .@@@@@@@@^  ,@@@@@@@@@@@@. =@@@@@@O    O@@@@@@. .[[.    =@@@@@@^
    //           ./@@@@`\@@@@@@@@\.    ,@@@@@@@@\.   .@@@@@@/    =@@@@@@O   .@@@@@@@.         =@@@@@@^
    //         ./@@@@/.  =@@@@@@@@@\`   ,@@@@@@@@@@\]@@@@@@O.    =@@@@@@@.  ,@@@@@@@^         /@@@@@@^
    //      =@@@@@@@@@^ ,@@@@@@@@@@@@@.   ,@@@@@@@@@@@@@@@`    ,@@@@@@@@@@^/@@@@@@@@@@\     ,@@@@@@@@@@`
    //      .[O@@@@@O[.  ,\@@@@@@@O/[.       .[\O@@@@/[`        ,\@@@@@@/[..[O@@@@@@O[.     .[\@@@@@@O[.
                                                                                                        




    //正在使用的
    log(R"( 
 
                                                      ..]]]]]]]]].                                              
                                        .,]/OOOOOOOOOOOOOOOOOOOOOO]`                                        
                                 ]/OOOOOOOOOOOOOOOOOOOOOOO@OOOOOOOOOOOO]                                    
                           ,]OO@@@@@@@@@OOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOO\]]]]]]`.                         
                       ]O@@OO@@@@@@@OOOOOOOOO@OOOO@@@@@OOOOOOOOOOOOOOOOOOOO@@O@@@@@OOOO]                    
                    ,O@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@OOOOOOOOOOOO@@@@@@@@@@@@OOOO`                 
                 ,/O@@O@OOOOOOOOOOOOOO@@@@@@@@@OOOOOOOOOOO@@@@@@@O. =OOOOOOOO@@@O@@@@@@@@@@O]               
               /OOO@@@@@OO@OOOOOOOOO@@@@@@@@@@@@@@@OOOO@OOOOO@@@@@O\O@OOOOOOOOOOOO@OO@OO@@@@@O\             
             /OO@@@@@@@@@@@@OOOOO@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOO@@OOOOOOOOOOOO@@@@@O\           
           =OO@@@@@@@@@@@OO@OOOOOO@@@@@OOOOOOOOOOOOOOOOOOOO@OOOOOO\OOOOOOOOOO@@OOOOOOOOOOOOOOOO@@O^         
          OOO@@@@@OO@OOO@OO@OOOOOOOO@@OOO@OOOOOOO@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOO@@@OOOOOOOOOOOOOOO`       
        ,O@@@@@@OOOO@OOO@OOO@OOOOOO@@@OOOO@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOO@@@@@OOOOOOO@OOOOOOO      
       =O@@@@@@OOOOO@@OO@@OOOOOOOOOO@@@OOOOO@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOO@@OOO@@@@@OOOOOOOOOOOOOOOO`    
      =OO@@@@@@OOOOO@@OO@@@OOOOOOOOOO@@@@OOOOOOO@@@@@@@OOOOOOOOOOOOOOOOOOO@@@@@OOOO@@@@OOOOOOO@@@OOOOOOO`   
     =OO@@@@@@O@OOOOO@@O@@@@OOOOOOOOOOO@@@OOOOOOOOOOOOO@OOOOOOOOOOOOOOOO@@@@@@@@OOO@@@@@@@@@OOO@@OOOOOOOO   
    =O@@@O@@@@OOOO@OOO@@@@OOOOOOOOOOOOOOO@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@OOO@@@@@/[O@@OOOOOOOOOOOO^  
   =@@OOO@@@@OOO@OOOOO@O@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@O@@@@@\,OO@OOOO[\OOOO@OO. 
  ,OOOOOOOOOOOOOOOO@OOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@OO^. =OOOOOOOO@O` 
 .OO/\OOO@O`OOOOO@OO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@O/..`..,[,OOOOOO@@^ 
 =@OOOOOOO`*O@@OOOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@OO`**...*,OOOOOO@@^   
.OOOOOOOO^..=O@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@O^*,***,/OOOOOO@@O 
=O@OOOOO^...,O@@@OOOOOOOO/.\/\OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO...*,^.,OOOO@O@^ 
=@@@OOOO.....=OOO@@OOOOOO\`/OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO/[OOO[O`/@OOO^........*OOOOOO^ 
=@@@@OOO.. ...\OOO@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OO` =@OOOOOO[[[\OO\o*..*]OOOOOO. 
=O@@@OOO..  ...=OOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@\......**\O/=\/OOOOOO`  
=@@@@@OO..   ....\OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@OOOOOOOOO`*  ... ..[`...\@O`   
 \O@@@OO^./OO/[`...[OOOOO.,OOOOOOOOOOOOOOOOOOO@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOOOO\`*..........=/     
  =@@OOOO...        ..[OOO\`,\OOO@OOOOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO.=.**...`.OO[       
   ,O@@OO.. ,...\....   .,OOO\.,\OOOO@@@OOOOOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOO@@@OOOO`..*]=[`..          
    ,@OOO^...OOOOOOOO`.    .,OOO\..,\OOOOOOO[[[[OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@OOOOO=^.,.[*`.]`      
     =OO@O\OOOOOOOOOOOO\.     ...[\O]...,[OOOOO\]]*]OOOOOOOOOOOOO[[OOOOOOOOOOOOO@@@@OOO@^=\OO.,,O,OOOO\     
     .OO@O^=^.OOOOOOOO.\O`        .............]OOOOOOOOOOOOOOOOO`......*OOOOOOOOO@@@@@OO`o.O.^..\^,\OOOO\` 
     .O/O@\.. OOOOOOOOO\OO.                 .,OOOOOOOOOOOOOOO^ =OOO/`...=O/`..[OO@@@@@@@@OO.O.=.\/O    ,\OOO
     =O =OO...  OOOOOOOOOO^                 ,O/.OOOOOOOOOOOOOOOO/OO/[...=^      \O@@@@@@OOO@O\/OOOO.       .
     =`  \O.. ..\OOOOOOOO^                 ..   =OOOOOOOOOOOOOOOOOO^....=......  \@@@@@OO/OO@OOOOOO^        
         =O^.  .,[[[[[[.                          .OOOOOOOOOOOOOO/,.  ..`... ..  O@@OOOOOOOO@OOOOOO^        
         .O.                                    ..,OOOOOOOOOOOOO[..   .....  .  /@@OO@OOOOOOOOOOOOO^        
          /. ..                                    ...[[O/[[[..       .....   ,OO@@@@@OOOOOOOOOOOOO`        
           .  .                                             ......   ..     ./OO@@@@@@OOOOOOOOOOOOO         
           ..                                             ........  ./]]]OOO@@OO@@@O@OOOOOOOOOOOOO^         
            ..                                          ........   /OOOOO@@@@@@@@@OOOOOOOOOOOOOOO^          
              .              .`                         ......  .,OOOO@@@@@@@@@@@@@@@OOOOOOOOOOO/           
                ..              ..........                    ./OOOOOO@@@@@@@@OO@@@@@@@@OOOOOOO/            
                  ...                                      .**..OOOOOO@@@@@@@@@@@O@@@@@@OOOOOO^             
                      ``                               ..,**....=OOOOOOO@@@@@@@@@OOO@OOOOOOO@@O             
                         [\`.                    ...*............OOOOOOOO@@@@@@@@@OOOOO. =OO@O^             
                             ,[\`.    .....]]*[`.     ..........,/OOOOOOOOO@@@@@@@@@@@OOOOO@O`              
                                 ,^=\/..         .    ...,]OOOOOOOOOOOOOOO@OO@@@@@@OOOO[O/[                 
                              .]OO./               .]/OOOOOOOOOOOOOOOOOOOOOOOOOOO@OOO/                      
                           ,/OOOO,`            ,/OOOOOOOOOOOOOOOOOOOOOOOOOOOO/`                             
                         ,OOOOOO`.         ,/OOOOOoooOOOOOOOOOOOOOOOOOOOOOOO`                               
                        /oooOOO`        ./OOoooooooooOOOOOOOOOOOOOOOOOOOOOOO\
                                                                                               )");
    log(R"(XGirl Self Development and improvement Edition.)");
    log(R"(XCore,小女孩自研版.)");
    log(R"(Maybe God is a girl...)"); 


    if (logExtraInfo)
        logExtraInfo();
}
