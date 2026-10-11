-- delete duplicate scholomance entrance doors
DELETE FROM `gameobject` WHERE `guid` IN (200263, 200977, 203093, 212798, 216460);
