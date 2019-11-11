var map;
var lista_pisos;
var markers = [];
var tipo;
//Se ejecuta al empezar
$(function () {
	getCiudades();
});


$(function () {
	tipo = window.localStorage.getItem("tipo");
	$("#lista_ciudades").change(function (event) {
		var nombre_ciudad = $("#lista_ciudades option:selected").val();
		$.ajax({
			type: "get",
			url: "../Server/map.php",
			data: {
				ciudad: nombre_ciudad
			},
			dataType: "json",
			success: function (response) {
				showMap(response.pisos);
			},
			error: function () {
				alert("Error inesperado");
			}
		});
	});
});

function rellenarLista(arrayCiudades) {
	for (var i = 0; i < arrayCiudades.length; i++) {
		var newElement = document.createElement("option");
		newElement.setAttribute("value", arrayCiudades[i]);
		var nombre_ciudad = arrayCiudades[i][0].toUpperCase() + arrayCiudades[i].slice(1);
		var texto = document.createTextNode(nombre_ciudad);
		newElement.appendChild(texto);
		document.getElementById("lista_ciudades").appendChild(newElement);
	}
}

function getCiudades() {
	$.ajax({
		type: "get",
		url: "../Server/ciudades.php",
		dataType: "json",
		success: function (response) {
			rellenarLista(response.ciudades);
		},
		error: function () {
			alert("Error inesperado");
		}
	});
}

function showMap(arrayPisos) {
	lista_pisos = arrayPisos;
	initMap(arrayPisos[0].latitud, arrayPisos[0].longitud);
	$("#map").show();
	for (var i = 0; i < arrayPisos.length; i++) {
		var piso = arrayPisos[i];
		var marker = new google.maps.Marker({
			position: {
				lat: parseFloat(piso.latitud),
				lng: parseFloat(piso.longitud),
			},
			title: piso.nombre,
			map: map,
			icon: "Iconos/home-icon-silhouette(2).png"
		});
		markers[i] = marker;
		marker.addListener('click', function (event) {
			//I know where it has been clicked and where is each marker so i can track which marker was clicked
			var i, found;
			for (i = 0, found = false; i < markers.length && found === false; i++) {
				if (event.latLng.lat() === markers[i].position.lat() &&
					event.latLng.lng() === markers[i].position.lng()) {
					found = true;
				}
			}
			i--;
			selectedMarker = i;
			idPiso = lista_pisos[selectedMarker].id;
			window.localStorage.setItem("idPiso", "" + idPiso);
			location.href = "detalles_piso.html";
		});
	}
}

function initMap(latitud, longitud) {
	var lat = parseFloat(latitud);
	var lng = parseFloat(longitud);
	// Map Options
	var options = {
		center: {
			lat: lat,
			lng: lng
		},
		zoom: 14,
	};

	// New map
	map = new google.maps.Map(document.getElementById('map'), options);
}