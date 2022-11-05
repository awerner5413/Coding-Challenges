-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.
-- query the crime scene reports to find the description of the crime we're investigating
--SELECT description
--FROM   crime_scene_reports
--WHERE  month = ('7')
--  AND  day = ('28')
--  AND  year = ('2021')
--  AND  street = ('Humphrey Street');
-- RESULT: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. || Littering took place at 16:36. No known witnesses.
-- KEY INFO: crime at 10:15am, Humphrey Street bakery. 3 witnesses, transcript mention bakery, someone at bakery at 16:36 (4:36pm)

-- query transcripts of interviews from robbery withnesses
--SELECT name, transcript
--FROM   interviews
--WHERE  month = ('7')
--  AND  day = ('28')
--  AND  year = ('2021')
--  AND  name IN ('Ruth', 'Eugene', 'Raymond');
-- RESULT: the witnesses of the theft are: Ruth, Eugene, and Raymond
-- KEY INFO: thief got in car 10 minutes after in parking lot, Eugene recognized theif, saw outside Emma's bakery withdrawing money at ATM on Leggett Street same day as crime but earlier
-- KEY INFO: thief on phone right after robbery, call < 60 sec, thief taking earliest flight (after 10:15am) out of Fiftyville NEXT DAY and this other person purchased tickets (Accomplice)

-- query ATM info looking for withdrawal transactions that day, use this as inner query to get acct # to join to bank accounts and then people
--SELECT *
--FROM   people p
--       JOIN bank_accounts b
--       ON b.person_id = p.id
--WHERE  account_number IN (SELECT account_number
--                            FROM   atm_transactions
--                            WHERE  month = ('7')
--                            AND  day = ('28')
--                            AND  year = ('2021')
--                            AND  transaction_type = ('withdraw')
--                            AND  atm_location = ('Leggett Street'))
-- RESULT: List of all the people that withdrew money the day of the crime at the ATM in question and I have all of their personal info
-- KEY INFO: One of these people is the theif, need more info

-- query phone logs to see if we can isolate the thief's call, happened right after robbery and lasted under a minute
--SELECT *
--FROM   phone_calls
--WHERE  month = ('7')
--  AND  day = ('28')
--  AND  year = ('2021')
--  AND  duration < 60;
-- RESULT: 9 calls fit the criteria - going to compare to ATM results to the caller # to see if I can narrow down a thief

-- query, combine the ATM and phone query to narrow down thief AND combine security logs query, add passengers search to discovered flight
SELECT *
FROM   people p
       JOIN bank_accounts b
       ON b.person_id = p.id
WHERE  account_number IN (SELECT account_number
                            FROM   atm_transactions
                            WHERE  month = ('7')
                            AND  day = ('28')
                            AND  year = ('2021')
                            AND  transaction_type = ('withdraw')
                            AND  atm_location = ('Leggett Street'))
  AND phone_number IN (SELECT caller
                        FROM   phone_calls
                        WHERE  month = ('7')
                        AND  day = ('28')
                        AND  year = ('2021')
                        AND  duration < 60)
  AND  license_plate IN (SELECT license_plate
                            FROM   bakery_security_logs
                            WHERE  month = ('7')
                            AND  day = ('28')
                            AND  year = ('2021')
                            AND  hour = ('10')
                            AND  minute BETWEEN 15 AND 25)
  AND passport_number IN (SELECT passport_number
                            FROM passengers p
                                   JOIN flights f
                                   ON p.flight_id = f.id
                            WHERE flight_id = 36);
-- RESULT: 5 people fit both criteria of withdrawing money from ATM and making the short phone call on day of crime

-- query flights to see who's leaving and line up with suspects query
--SELECT *
  --FROM flights f
    --   JOIN airports a
      --        ON destination_airport_id = a.id
 --WHERE month = ('7')
--   AND day = ('29')
   --AND year = ('2021')
   --AND origin_airport_id = ('8')
--ORDER BY hour;
-- RESULT: fiftyville airport ID is 8; earliest flight out of 8 is at 12:15pm, headed toward NYC, which is the city fled to! Flight ID 36

-- need to find out who the accomplice is by seeing who bought the tickets for the flight out, person Bruce was on the phone with
--SELECT *
--FROM   phone_calls
--WHERE  month = ('7')
--  AND  day = ('28')
--  AND  year = ('2021')
--  AND  duration < 60
--  AND  caller = ('(367) 555-5533');
-- RESULT: accomplice number is 375 555 8161

SELECT name
FROM   people
WHERE  phone_number IN (SELECT receiver
                            FROM   phone_calls
                            WHERE  month = ('7')
                            AND  day = ('28')
                            AND  year = ('2021')
                            AND  duration < 60
                            AND  caller = ('(367) 555-5533'))