PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central del grupo):
	-	Acceda la página de la [Práctica 2](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.

	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual, usando el repositorio remoto en GitHub como repositorio central para el trabajo colaborativo
	de los distintos miembros del grupo de prácticas o como copia de seguridad.
	-	Puede *confirmar* versiones del proyecto en su directorio local con las órdenes siguientes:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

	-	Las versiones confirmadas, y sólo ellas, se almacenan en el repositorio y pueden ser accedidas en cualquier momento.

*	Para interactuar con el contenido remoto en GitHub es necesario que los cambios en el directorio local estén confirmados.

	-	Puede comprobar si el directorio está *limpio* (es decir, si la versión actual está confirmada) usando el comando
		`git status`.

	-	La versión actual del directorio local se sube al repositorio remoto con la orden:

		```.sh
		git push
		```

		*	Si el repositorio remoto contiene cambios no presentes en el directorio local, `git` puede negarse
			a subir el nuevo contenido.

			-	En ese caso, lo primero que deberemos hacer es incorporar los cambios presentes en el repositorio
				GitHub con la orden `git pull`.

			-	Es posible que, al hacer el `git pull` aparezcan *conflictos*; es decir, ficheros que se han modificado
				tanto en el directorio local como en el repositorio GitHub y que `git` no sabe cómo combinar.

			-	Los conflictos aparecen marcados con cadenas del estilo `>>>>`, `<<<<` y `====`. Los ficheros correspondientes
				deben ser editados para decidir qué versión preferimos conservar. Un editor avanzado, del estilo de Microsoft
				Visual Studio Code, puede resultar muy útil para localizar los conflictos y resolverlos.

			-	Tras resolver los conflictos, se ha de confirmar los cambios con `git commit` y ya estaremos en condiciones
				de subir la nueva versión a GitHub con el comando `git push`.


	-	Para bajar al directorio local el contenido del repositorio GitHub hay que ejecutar la orden:

		```.sh
		git pull
		```
	
		*	Si el repositorio local contiene cambios no presentes en el directorio remoto, `git` puede negarse a bajar
			el contenido de este último.

			-	La resolución de los posibles conflictos se realiza como se explica más arriba para
				la subida del contenido local con el comando `git push`.



*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los
elementos más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.

![Etiquetado de la señal](img/capt1.png)

Este es el contenido del fichero de transcripción *.lab*. Con este formato analizaremos después la calidad de nuestro detector. 

```
0.0000000 0.4732398 S
0.4732398 1.6485528 V
1.6485528 1.8876495 S
1.8876495 2.8659600 V
2.8659600 3.7959175 S
3.7959175 5.1608672 V
5.1608672 5.8699940 S
5.8699940 7.5984906 V
7.5984906 7.8447152 S
```

- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para
	  estar seguros de que un segmento de señal se corresponde con voz.

	  	> Pondremos un nivel de 15 dB sobre el silencio para suponer que estamos analizando señal que incluye voz.

	* Duración mínima razonable de los segmentos de voz y silencio.

		> El silencio más corto que hemos etiquetado en nuestro audio dura aproximadamente 200 ms, dejaremos un pequeño margen y estableceremos un tiempo mínimo de 150 ms. El segmento de voz de menor duración que hemos etiquetado dura 960 ms, dejando margen, podemos exigir 600 ms de voz para etiquetar el segmento como tal.



	* ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?
		
		> Notamos que en las transiciones de segmentos de silencio a voz, es decir, al inicio de palabras, suele haber picos en la tasa de cruces por cero. Además, este parametro suele ser mas ruidoso y alto en los segmentos de silencio.


### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal en
  tiempo real tan exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.

	> Jugando con los parametros del detector, encontramos un buen resultado sobre la base de datos con los siguientes valores:

	```
	vad_data->alpha1 = 2.06;
	vad_data->alpha2 = 6.91;
	vad_data->min_silence = 0.069;
	vad_data->min_voice = 0.01;
	```
	> El resultado:
	```
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4151.lab: 94.679%
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4152.lab: 73.730%
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4161.lab: 89.006%
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4171.lab: 79.728%
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4172.lab: 76.947%
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4305.lab: 94.749%
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4311.lab: 88.366%
	===> /home/jaumecort/PAV/P2/db.v4/2014/pav_4341.lab: 87.823%
	===> /home/jaumecort/PAV/P2/db.v4/2015/pav_2109.lab: 89.056%
	===> /home/jaumecort/PAV/P2/db.v4/2015/pav_2110.lab: 94.363%
	===> /home/jaumecort/PAV/P2/db.v4/2015/pav_2151.lab: 90.985%
	===> /home/jaumecort/PAV/P2/db.v4/2015/pav_2152.lab: 96.663%
	===> /home/jaumecort/PAV/P2/db.v4/2015/pav_2171.lab: 94.066%
	===> /home/jaumecort/PAV/P2/db.v4/2015/pav_2172.lab: 94.794%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_1341.lab: 90.168%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4111.lab: 93.906%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4112.lab: 87.685%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_41191.lab: 91.705%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_41192.lab: 95.665%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_412_1.lab: 80.134%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4131.lab: 82.431%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4132.lab: 85.378%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4151.lab: 94.954%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4161.lab: 90.051%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_418.lab: 95.295%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4311.lab: 95.274%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4312.lab: 94.844%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4313.lab: 94.906%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4321.lab: 89.972%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4331.lab: 91.095%
	===> /home/jaumecort/PAV/P2/db.v4/201617q1/pav_4351.lab: 91.959%
	===> /home/jaumecort/PAV/P2/db.v4/201617q2/pav_1121.lab: 85.565%
	===> /home/jaumecort/PAV/P2/db.v4/201617q2/pav_1131.lab: 94.772%
	===> /home/jaumecort/PAV/P2/db.v4/201617q2/pav_1141.lab: 88.588%
	===> /home/jaumecort/PAV/P2/db.v4/201617q2/pav_1171.lab: 85.049%
	===> /home/jaumecort/PAV/P2/db.v4/201617q2/pav_2151.lab: 91.532%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q1/pav_1131.lab: 93.439%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q1/pav_4115.lab: 89.022%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q1/pav_4131.lab: 92.590%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q1/pav_4141.lab: 89.442%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q1/pav_4161.lab: 93.706%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q1/pav_4171.lab: 97.499%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q1/pav_4341.lab: 93.562%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_137.lab: 89.427%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_2121.lab: 91.545%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_2141.lab: 95.142%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_2142.lab: 76.713%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_2171.lab: 91.923%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_2191.lab: 96.376%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_231.lab: 87.905%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_232.lab: 90.602%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_233.lab: 94.578%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_2342.lab: 89.767%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_236.lab: 94.885%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_237.lab: 89.270%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_238.lab: 85.912%
	===> /home/jaumecort/PAV/P2/db.v4/2017-18q2/pav_239.lab: 93.650%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4111.lab: 94.173%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4112.lab: 74.330%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4121.lab: 97.737%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4122.lab: 95.165%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4131.lab: 92.876%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4132.lab: 89.178%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4141.lab: 83.853%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4151.lab: 96.068%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4161.lab: 93.891%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4171.lab: 89.924%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4172.lab: 79.720%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4181.lab: 92.003%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4182.lab: 87.731%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4341.lab: 90.052%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4342.lab: 80.569%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4351.lab: 89.457%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4352.lab: 81.925%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4361.lab: 86.973%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4362.lab: 97.925%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4371.lab: 97.712%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4372.lab: 96.394%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4382.lab: 86.565%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q1/pav_4385.lab: 88.886%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_21101.lab: 63.405%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2111.lab: 87.631%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2121.lab: 96.916%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2131.lab: 87.507%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2141.lab: 94.928%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2151.lab: 87.333%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2152.lab: 93.910%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2161.lab: 92.272%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2171.lab: 94.834%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_21x1.lab: 95.256%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_231001.lab: 90.337%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2311.lab: 87.036%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2321.lab: 96.545%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2331.lab: 88.360%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2341.lab: 89.185%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2342.lab: 95.757%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_235.lab: 90.281%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2361.lab: 92.152%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2371.lab: 96.814%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2372.lab: 86.991%
	===> /home/jaumecort/PAV/P2/db.v4/2018-19q2/pav_2381.lab: 86.950%
	**************** Summary ****************
	===> TOTAL: 91.222%
	````

- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 

![Etiquetado y VAD de la señal](img/capt2.png)

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.


### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que
  considere de interés de cara a su evaluación.


### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.
