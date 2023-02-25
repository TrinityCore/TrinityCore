===================================================================
Light Mapper 1.0 | ReadMe | Thursday, August 13, 2009
Copywrite (c) 2009 Anarchy Games Software. All rights reserved.
===================================================================
Contact me at snobaste@gmail.com for any errors, bugs, or questions
===================================================================

|-----------------------------------------------------------------|
|---------About---------------------------------------------------|
|-----------------------------------------------------------------|
|  Light Mapper started as a simple idea to graphically represent |
|  data in the Light.dbc file. The first version was very simple, |
|  and was only created in order to aid me in making a few model  |
|  changes for a machinima. After I had finished that machinima,  |
|  however, I decided that the program could be much more than I  |
|  had originally made it as.                                     |
|-----------------------------------------------------------------|
|---------System Requirements-------------------------------------|
|-----------------------------------------------------------------|
|  A 1.5GHz processor or higher                                   |
|  256MB of free RAM                                              |
|  A monitor with a resolution larger than 1024x768               |
|-----------------------------------------------------------------|
|---------Usage---------------------------------------------------|
|-----------------------------------------------------------------|
|  When you open up Light Mapper, you will be prompted to select  |
|  a map to view. A map will be on the list if an image for it    |
|  exists in the "maps" folder. Once you select the map, the main |
|  window will appear, and load the map. Once in the map, you can |
|  click and drag to move around. Alternately, you can also use   |
|  the arrow keys to move the map. There is a mini-map in the top |
|  right of the screen. This shows your current position in the   |
|  map. You can also click and drag the minimap marker to position|
|  yourself.                                                      |
|                                                                 |
|  All the red dots on the map are entries in Light.dbc. These    |
|  are mapped to the light's actual position's in the world. Hover|
|  over one, and the size of its radius will appear. The inner    |
|  radius is more opaque than the outer. Information about the    |
|  light will also appear on the bottom right of the screen. The  |
|  ID can be used to find the light in the DBC so that it can be  |
|  copied/modified.                                               |
|                                                                 |
|  The user can press Escape or click the close box of the main   |
|  window to return to the map selection list.                    |
|-----------------------------------------------------------------|
|--------Controls-------------------------------------------------|
|-----------------------------------------------------------------|
| Mouse (Left-click and Drag) - Moves the map. When used on mini  |
|                               map, moves the map directly to    |
|                               point clicked on.                 |
| Arrow Keys                  - Scrolls the map.                  |
| Mouse Wheel (Up and Down)   - Scrolls through the light color   |
|                               settings. SEE NOTES.              |
| Escape Key                  - When pressed in the map selection |
|                               screen, quits the program. When   |
|                               used in the main screen, goes back|
|                               to the map selection screen.      |
| R                           - Resets view to the center of the  |
|                               map.                              |
| A                           - Toggles the showing of ALL light  |
|                               radii. Can affect performance.    |
|                               When a light dot is hovered over  |
|                               all other lights disappear until  |
|                               you de-select the light.          |
| M                           - Toggles the showing of light dots |
|                               on the minimap as well.           |
| H                           - For performance reasons, lights   |
|                               with a radius larger than 100000  |
|                               are shrunk. Pressing this key will|
|                               toggle that shrinking. WARNING:   |
|                               When the shrinking is off, some   |
|                               maps (such as "developer") will   |
|                               cause an extremely low framerate! |
|-----------------------------------------------------------------|
|---------Notes---------------------------------------------------|
|-----------------------------------------------------------------|
|--- About Light Types -------------------------------------------|
|-----------------------------------------------------------------|
| The light radii can be shown using different data from the      |
| LightIntBand.dbc file. By default, the radii show up in the fog |
| color for that zone. Using the mouse wheel scrolls through all  |
| modes:                                                          |
|      Global Diffusion - The color of the diffusion (bloom) in   |
|                         that zone.                              |
|                                                                 |
|      Global Ambient - The color of the ambient lighting in the  |
|                       zone. This color also slightly shades the |
|                       in-game minimap.                          |
|                                                                 |
|      Sky A - The color of the sky at its zenith (top)           |
|                                                                 |
|      Sky B - The color of the sky below Sky A                   |
|                                                                 |
|      Sky C - The color of the sky below Sky B                   |
|                                                                 |
|      Sky D - The color of the sky below Sky C                   |
|                                                                 |
|      Sky E - The color of the sky below Sky D                   |
|                                                                 |
|      Fog - The color of the fog and "background mountains" in   |
|            the zone. Also the color of the entire bottom half   |
|            of the sky.                                          |
|                                                                 |
|      Unknown - [could be smoke tinting?]                        |
|                                                                 |
|      Sun - The tint of the sun and all other celestial bodies.  |
|            Also the specular (reflection) color.                |
|                                                                 |
|      Cloud A - The base color of the clouds. This will mix with |
|                other cloud colors.                              |
|                                                                 |
|      Cloud B - The color of the outer edge of the clouds.       |
|                                                                 |
|      Cloud A-2 - [not sure if used] Provides color accents on   |
|                  the clouds.                                    |
|                                                                 |
|      Unknown - [no idea what this one is]                       |
|                                                                 |
|      Ocean Water - The color of the (more shallow) ocean in the |
|                    zone.                                        |
|                                                                 |
|      Fatigue Water - The color of the (deeper) ocean in the     |
|                      zone.                                      |
|                                                                 |
|      Shallow Fresh Water - The color of the shallow fresh water |
|                            (rivers, streams, lakes).            |
|                                                                 |
|      Deep Fresh Water - The color of the deeper fresh water     |
|                         (rivers, streams, lakes).               |
|                                                                 |
|-----------------------------------------------------------------|
|--- About Global Lights and Northrend ---------------------------|
|-----------------------------------------------------------------|
| Almost every map has a global light. These will have a position |
| of 0, 0, 0, and will be at the upper-left hand corner of every  |
| map. Even though these have a very small radius, they actually  |
| cover the entire map. The global lights are used when there is  |
| no other lighting to use.                                       |
|                                                                 |
| Northrend and a few other Wrath of the Lich King maps' lights   |
| are a little different. These maps have a per-zone global light.|
| Every zone has a very small light in (approximately) the center |
| of the zone. These will have a small radius (between around 200 |
| and 400). Although they look small, they actually cover the     |
| entire zone in which they reside.                               |
|-----------------------------------------------------------------|