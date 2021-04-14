CREATE TABLE `character_arena_stats` (
`guid`  int(10) NOT NULL ,
`slot`  smallint(1) NOT NULL ,
`personal_rating`  int(10) NOT NULL ,
`matchmaker_rating`  int(10) NOT NULL ,
PRIMARY KEY (`guid`, `slot`)
);
