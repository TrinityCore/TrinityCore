DELETE FROM `command` WHERE `name` = "go xy";
UPDATE `command` SET `help` = "Syntax: .go xyz #x #y [#z [#mapid [#orientation]]]

Teleport player to point with (#x,#y,#z) coordinates at map #mapid with orientation #orientation. If z is not provided, ground/water level will be used. If mapid is not provided, the current map will be used. If #orientation is not provided, the current orientation will be used." WHERE `name` = "go xyz";