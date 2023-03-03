ALTER TABLE guild_member ADD COLUMN recipesMask1 varchar(1300) NOT NULL DEFAULT '' AFTER profRank1;
ALTER TABLE guild_member ADD COLUMN recipesMask2 varchar(1300) NOT NULL DEFAULT '' AFTER profRank2;