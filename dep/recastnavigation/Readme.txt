
Recast & Detour Version 1.4


Recast

Recast is state of the art navigation mesh construction toolset for games.

    * It is automatic, which means that you can throw any level geometry
      at it and you will get robust mesh out
    * It is fast which means swift turnaround times for level designers
    * It is open source so it comes with full source and you can
      customize it to your hearts content. 

The Recast process starts with constructing a voxel mold from a level geometry 
and then casting a navigation mesh over it. The process consists of three steps, 
building the voxel mold, partitioning the mold into simple regions, peeling off 
the regions as simple polygons.

   1. The voxel mold is build from the input triangle mesh by rasterizing 
      the triangles into a multi-layer heightfield. Some simple filters are 
      then applied to the mold to prune out locations where the character 
      would not be able to move.
   2. The walkable areas described by the mold are divided into simple 
      overlayed 2D regions. The resulting regions have only one non-overlapping 
      contour, which simplifies the final step of the process tremendously.
   3. The navigation polygons are peeled off from the regions by first tracing 
      the boundaries and then simplifying them. The resulting polygons are 
      finally converted to convex polygons which makes them perfect for 
      pathfinding and spatial reasoning about the level. 

The toolset code is located in the Recast folder and demo application using the Recast
toolset is located in the RecastDemo folder.


Detour

Recast is accompanied with Detour, path-finding and spatial reasoning toolkit. You can use any navigation mesh with Detour, but of course the data generated with Recast fits perfectly.

Detour offers simple static navigation mesh which is suitable for many simple cases, as well as tiled navigation mesh which allows you to plug in and out pieces of the mesh. The tiled mesh allows to create systems where you stream new navigation data in and out as the player progresses the level, or you may regenerate tiles as the world changes. 


Latest code available at https://github.com/memononen/recastnavigation

Mikko Mononen
memon@inside.org
