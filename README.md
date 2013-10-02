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



###Arbetsflöde
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
   
##Komma igång: LPCXpresso

1. Installera LPCXpresso från http://lpcware.com/lpcxpresso/download
2. När programmet startar får du frågan om var du vill ha ditt workspace. Välj samma mapp som ovan, alltså i det här exemplet `/User/albert/sumo/`.
3. Skapa ett nytt tomt projekt som heter EDwin och importera koden som redan finns i mappen.


##Arkitektur
Koden består av tre lager.

1. APP (Application Layer) - själva beteendet, består av en state machine.
2. PAL (Peripheral Abstraction Layer) - funktioner för att kontrollera H-bryggor, sensorer osv.
3. HAL (Hardware Abstraction Layer) - funktioner för att använda de olika delarna i mikrokontrollern, timers, ADC osv.

###HAL
Det finns ett färdigt hårdvaruabstraktionslager för ARM-processorer som kommer från ARM själva och heter CMSIS. Vi använder det, det verkar bra. Och så slipper vi skriva ett eget.

###PAL
För att skilja det från HAL så uppfann vi Peripheral Abstraction Layer som är ungefär samma sak fast för våra specifika delar av hårdvaran som finns utanför roboten. Här finns funktioner som till exempel palMotorSetSpeed() och palLineSensorGetSensorValue(). PAL använder HAL.

###APP
Applikationslagret är koden som bestämmer hur roboten beter sig. Det är här vi använder PAL-funktionerna och fattar beslut. Vår applikation fungerar som en tillståndsmaskin (state machine) [https://sv.wikipedia.org/wiki/Tillst%C3%A5ndsmaskin]().

![image](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1f/State-machine-1-2.svg/350px-State-machine-1-2.svg.png)

Varje tillstånd har en enkel funktion, till exempel "åk framåt". När funktionen utförts kollar tillståndet vad som ska bli nästa tillstånd, dvs vilken pil som ska följas i diagrammet. Varje par av "runState()" och "nextState()"-funktioner paras ihop till ett tillstånd (state). I applikationslagret finns en struct för detta vilket ger oss en väldigt enkel och snygg main-loop:

	int main(){

		State currentState = initialState;

		while (1)
		{	
			status = currentState->runState();
			status = currentState->nextState(currentState);
		}
	}
