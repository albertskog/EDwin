#EDwin

Detta är vårat repository!

##Komma igång: Git
_Följande instruktioner funkar för mac, bör vara liknande för folk med Windowns_

1. Skapa en ny mapp där du vill ha all din kod. Till exempel `/User/albert/sumo/`.
2. Öppna terminalen och gå till den mapp där du vill lägga din kopia av koden. `/User/<användarnamn>/` är din hem-katalog och kan förkortas med `~`.
    ```sh
    $ cd ~/sumo/
    ```
    
3. Klona koden från GitHub:
    ```sh
    $ git clone https://github.com/albertskog/EDwin.git
    ```

4. Klart! Koden finns nu i `~/sumo/EDwin`


##Komma igång: LPCXpresso

1. Installera LPCXpresso från http://lpcware.com/lpcxpresso/download
2. När programmet startar får du frågan om var du vill ha ditt workspace. Välj samma mapp som ovan, alltså i det här exemplet `/User/albert/sumo/`.
3. Skapa ett nytt tomt projekt som heter EDwin och importera koden som redan finns i mappen.

##Arbetsflöde
Så här arbetar du med Git:

1. Se först till att du har senaste versionen av koden innan du börjar göra ändringar. Gå till din EDwin-mapp och ladda ner senaste koden från GitHub:
    ```sh
    $ cd ~/sumo/EDwin
    $ git pull
    ```

2. Om allt gick bra är det bara att börja koda!
3. När du är klar, "markera" alla filer du har ändrat. Till exempel main.c:
    ```sh
    $ git add main.c
    ```

4. Spara alla ändringar till en ny _commit_ och ge den en vettig kommentar. Detta gör man typiskt sett för varje specifik sak man ändrar.
    ```sh
    $ git commit -m "lade till kod för reflexsensorer"
    ```

5. Ladda upp ändringarna till GitHub. Detta kan vara flera commits och görs typiskt sett när man kodat klart för stunden och vill ge andra chansen att ta del av ens ändringar.
    ```sh
    $ git push
   ```
