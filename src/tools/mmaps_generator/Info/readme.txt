R"(Generator command line args

--threads           [#]             Max number of threads used by the generator
                                    Default: Same as CPU cores

--offMeshInput      [file.*]        Path to file containing off mesh connections data.
                                    Format must be: (see offmesh_example.txt)
                                    "map_id tile_x,tile_y (start_x start_y start_z) (end_x end_y end_z) size  //optional comments"
                                    Single mesh connection per line.

--silent            []              Make us script friendly. Do not wait for user input
                                    on error or completion.

--bigBaseUnit       [true|false]    Generate tile/map using bigger basic unit.
                                    Use this option only if you have unexpected gaps.

                                    false: use normal metrics (default)

--maxAngle          [#]             Max walkable inclination angle

                                    float between 45 and 90 degrees (default 55)

--skipLiquid        [true|false]    extract liquid data for maps

                                    false: include liquid data (default)

--skipContinents    [true|false]    continents are maps 0 (Eastern Kingdoms),
                                    1 (Kalimdor), 530 (Outlands), 571 (Northrend)

                                    false: build continents (default)

--skipJunkMaps      [true|false]    junk maps include some unused
                                    maps, transport maps, and some other

                                    true: skip junk maps (default)

--skipBattlegrounds [true|false]    does not include PVP arenas

                                    false: skip battlegrounds (default)

--debugOutput       [true|false]    create debugging files for use with RecastDemo
                                    if you are only creating mmaps for use with MaNGOS,
                                    you don't want debugging files

                                    false: don't create debugging files (default)

--tile              [#,#]           Build the specified tile
                                    seperate number with a comma ','
                                    must specify a map number (see below)
                                    if this option is not used, all tiles are built

                    [#]             Build only the map specified by #
                                    this command will build the map regardless of --skip* option settings
                                    if you do not specify a map number, builds all maps that pass the filters specified by --skip* options

--help                              This message

examples:

mmaps_generator
builds maps using the default settings (see above for defaults)

mmaps_generator --skipContinents true
builds the default maps, except continents

mmaps_generator 0
builds all tiles of map 0

mmaps_generator 0 --tile 34,46
builds only tile 34,46 of map 0 (this is the southern face of blackrock mountain)
)"