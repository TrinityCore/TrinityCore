DELETE FROM trinity_string WHERE entry in (349, 350, 351, 352, 353, 354, 355, 356);

INSERT INTO trinity_string  (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`)
VALUES
 (349,'%d (idx:%d) - |cffffffff|Htitle:%d|h[%s %s]|h|r %s %s ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
 (350,'%d (idx:%d) - [%s %s] %s %s ',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
 (351,'No titles found!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
 (352,'Invalid title id: %u',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
 (353,'Title %u (%s) added to known titles list for player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
 (354,'Title %u (%s) removed from known titles list for player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
 (355,'Title %u (%s) set as current seelcted title for player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
 (356,'Current selected title for player %s reset as not known now.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
