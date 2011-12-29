-- The Cleansing fix by shlomi1515
-- Closes #3582

DELETE FROM gameobject WHERE guid=150377;
UPDATE gameobject_template SET data2=11322 WHERE entry=186649;

DELETE FROM event_scripts WHERE id=11322;
INSERT INTO event_scripts VALUES 
(11322,1,8,27959,0,0,0,0,0,0);
