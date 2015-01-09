-- the brazier should summon multiple bosses, this is part of 
-- an instance encounter and should be handled via cpp
DELETE FROM `gameobject_scripts` WHERE `id` IN (28704,21608,21609,21610); 
DELETE FROM gameobject WHERE guid IN (21608,21609,21610);
