﻿# LoggerFactoryPattern

Logger 기능을 Factory Pattern으로 구성


Logger Class는 3가지 기능을 가짐 -> Info, Warn, error 
Logger Class를 기반으로 하는 Child Class는 3가지의 종류가 있음 -> File, Database, Console


해당 팩토리 패턴에서 지켜야 할 원칙 -> OCP(개방 폐쇄), Single Responsibility(단일 책임)


Time이란 Single 을 구현하여 오늘의 날짜를 string 형태로 불러와 로그에 적용하도록 함
