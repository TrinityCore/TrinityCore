-- fix graveyard for shattered halls, alliance to honor hold, horde to thrallmar, not the other way around
UPDATE `game_graveyard_zone` SET `faction`=67 WHERE `id`=919 AND `ghost_zone`=3714;
UPDATE `game_graveyard_zone` SET `faction`=469 WHERE `id`=920 AND `ghost_zone`=3714;
