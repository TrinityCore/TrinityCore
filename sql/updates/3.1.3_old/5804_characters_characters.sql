/*
-- Broken character data blobs lately? Run this!
-- UPDATE `characters` SET `data`=CONCAT(SUBSTRING_INDEX(`data`,' ',1248), ' ',SUBSTRING_INDEX(`data`,' ',-(1295-1248))) WHERE SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',1295+1),' ',-1) IS NOT NULL;
*/
