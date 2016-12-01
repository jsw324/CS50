-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `user_id` int(10) NOT NULL,
  `transaction` varchar(5) NOT NULL,
  `datetime` varchar(255) NOT NULL,
  `symbol` varchar(5) NOT NULL,
  `shares` int(255) NOT NULL,
  `price` decimal(10,2) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=42 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (19,16,'BUY','Thursday 1st of December 2016 09:36:07 PM','C',10,57.27),(20,16,'SELL','Thursday 1st of December 2016 09:36:12 PM','C',0,57.27),(21,16,'BUY','Thursday 1st of December 2016 09:40:43 PM','C',10,57.27),(22,16,'SELL','Thursday 1st of December 2016 09:42:28 PM','C',0,57.27),(23,16,'BUY','Thursday 1st of December 2016 09:43:10 PM','C',20,57.27),(24,16,'SELL','Thursday 1st of December 2016 10:23:28 PM','C',20,57.27),(25,16,'BUY','Thursday 1st of December 2016 10:24:15 PM','C',10,57.27),(26,16,'BUY','Thursday 1st of December 2016 10:24:21 PM','F',20,12.43),(27,16,'BUY','Thursday 1st of December 2016 10:25:05 PM','AMZN',10,743.65),(28,16,'SELL','Thursday 1st of December 2016 10:25:08 PM','AMZN',10,743.65),(29,16,'SELL','Thursday 1st of December 2016 10:25:11 PM','C',10,57.27),(30,16,'SELL','Thursday 1st of December 2016 10:25:13 PM','F',20,12.43),(31,16,'DEPO','Thursday 1st of December 2016 10:41:39 PM','',0,500.00),(32,16,'BUY','Thursday 1st of December 2016 10:42:41 PM','C',100,57.27),(33,16,'SELL','Thursday 1st of December 2016 10:42:45 PM','C',100,57.27),(34,16,'BUY','Thursday 1st of December 2016 10:44:01 PM','F',10,12.43),(35,16,'SELL','Thursday 1st of December 2016 10:44:12 PM','F',10,12.43),(36,16,'BUY','Thursday 1st of December 2016 10:44:37 PM','F',10,12.43),(37,16,'SELL','Thursday 1st of December 2016 10:45:27 PM','F',10,12.43),(38,16,'BUY','Thursday 1st of December 2016 10:47:52 PM','C',15,57.27),(39,16,'SELL','Thursday 1st of December 2016 10:49:37 PM','C',15,57.27),(40,16,'BUY','Thursday 1st of December 2016 10:49:57 PM','C',25,57.27),(41,16,'SELL','Thursday 1st of December 2016 10:49:59 PM','C',25,57.27);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `shares` int(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=60 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.0000),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.0000),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.0000),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.0000),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.0000),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.0000),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.0000),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.0000),(9,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',10000.0000),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.0000),(14,'monty','$2y$10$c1NNGwS9VeNfUxrcMQxVUeG4roDUIZye5BUShlEEBQSBhvC8ApnR.',10000.0000),(15,'hannah','$2y$10$VyIbmOKlEgFZU4SJM5MP5eJHIN5pI24j1ZolsguyEqAfpJhyUooMO',10000.0000),(16,'jsw324','$2y$10$x3w6TEk7sW1hfhe/UoRuOOKTjNAOtSTM270Z13Dh8TIztnOLsLgPy',10000.0000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-12-01 23:04:07
