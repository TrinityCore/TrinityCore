-- Marin Noggenfogger should mix the elixir before quest 2662 completes
UPDATE `smart_scripts` SET `event_type`=19, `comment`= "Marin Noggenfogger - On Quest 'Noggenfogger Elixir' Taken - Run Script"
 WHERE `entryorguid`= 7564 AND `source_type`= 0;
