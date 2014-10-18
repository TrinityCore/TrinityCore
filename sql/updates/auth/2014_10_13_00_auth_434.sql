ALTER TABLE `battlenet_modules`
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`Name`, `System`);
DELETE FROM `battlenet_modules` WHERE `Name` IN ('ERRS','PFTY');
INSERT INTO `battlenet_modules` (`Hash`,`Name`,`Type`,`System`,`Data`) VALUES
('cc654428261322763f4cada5b7f4b3b67660e85639bea916986b3f366fe8adc2', 'ERRS',  'xml', 'enGB', 'AA6C50D3'),
('2753d31092f1978bdd78ebd4fae2d189364ad7108ceb22fbf1413be1f43bef04', 'PFTY', 'pfty', 'zhCN', 'DF6C50D3'),
('5813f318f7e40a07a7cdfeeec9827942e6fdc5ccee0d4171148443e429ad0ead', 'PFTY', 'pfty', 'ruRU', 'DF6C50D3'),
('83663d54444eadad40d43725e59bde8eda10276e76fc3c4e6f2ca56332ee8f03', 'PFTY', 'pfty', 'enSG', 'DF6C50D3'),
('870f53d10b4e1b09d6b622cd5671ba4ff1ad69512dfa2c676072c52e45c7f0f9', 'PFTY', 'pfty', 'esES', 'DF6C50D3'),
('305bbdab1953e65974a249e276867e13ad2c3cabca3668983cb5ed406251bb7b', 'PFTY', 'pfty', 'frFR', 'DF6C50D3'),
('83663d54444eadad40d43725e59bde8eda10276e76fc3c4e6f2ca56332ee8f03', 'PFTY', 'pfty', 'enGB', 'DF6C50D3'),
('a2ec4b41148214037a2e89a2e557af716d085241b81f5244494bdc77a891ca38', 'PFTY', 'pfty', 'csCZ', 'DF6C50D3'),
('a8c77051991b1a6c5dfe412e9f46d8f584349996fbde37c4f2a527c192163502', 'PFTY', 'pfty', 'plPL', 'DF6C50D3'),
('83663d54444eadad40d43725e59bde8eda10276e76fc3c4e6f2ca56332ee8f03', 'PFTY', 'pfty', 'enUS', 'DF6C50D3'),
('7466b2db3f03768aa2527535d4b3c6c9ef9e8fb07c6db88b1019f3d25a2942e8', 'PFTY', 'pfty', 'koKR', 'DF6C50D3'),
('a2ec4b41148214037a2e89a2e557af716d085241b81f5244494bdc77a891ca38', 'PFTY', 'pfty', 'jaJP', 'DF6C50D3'),
('3e381d4f83201f4e3c482eb74da12e5ff9dd924da2413d8fb33f5eea9a02c2c2', 'PFTY', 'pfty', 'zhTW', 'DF6C50D3'),
('83663d54444eadad40d43725e59bde8eda10276e76fc3c4e6f2ca56332ee8f03', 'PFTY', 'pfty', 'enTH', 'DF6C50D3'),
('b72e65b6b34d8f859e79b5f28952e26553a796d5e1d75c2b5930bc0daeaa728c', 'PFTY', 'pfty', 'itIT', 'DF6C50D3'),
('e8b82becbe0a0a1bbb5561df69320edbd770897a8deaab23caa6736255e0dc33', 'PFTY', 'pfty', 'esMX', 'DF6C50D3'),
('83663d54444eadad40d43725e59bde8eda10276e76fc3c4e6f2ca56332ee8f03', 'PFTY', 'pfty', 'enAU', 'DF6C50D3'),
('0a3f6f3f0535ea21dbe620085192afc796203047e270e0e1b76f15a739fe1797', 'PFTY', 'pfty', 'ptBR', 'DF6C50D3'),
('047329d08d433da2622e9fc2ee96c8dd8f35e7770699d07cf74855b9c8ea9125', 'PFTY', 'pfty', 'deDE', 'DF6C50D3');
