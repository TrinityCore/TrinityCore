ALTER TABLE `disables` 
ADD COLUMN params_0 varchar (255) NOT NULL default '' AFTER flags,
ADD COLUMN params_1 VARCHAR (255) NOT NULL default '' AFTER params_0;
