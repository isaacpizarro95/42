var idPiso;
var datos = [];

$(function () {
	var test = window.localStorage.getItem("tipoUser");
	if (window.localStorage.getItem("tipoUser") == "-1") {
		$("input").attr("disabled", "disabled");
	} else {
		permitirModificarDatos();
	}
	idPiso = window.localStorage.getItem("idPiso");
	$.ajax({
		type: "get",
		url: "../Server/centros.php",
		data: {
			id: idPiso
		},
		dataType: "json",
		success: function (response) {
			console.log(response);
			var detalles_piso = response.detalles_piso;
			if (typeof detalles_piso !== "undefined") {
				console.log(detalles_piso);
				$("#nombre").html(detalles_piso.nombre.toUpperCase());
				datos["nombre"] = detalles_piso.nombre;
				$("#aforo").val(detalles_piso.aforo);
				datos["aforo"] = detalles_piso.aforo;
				$("#num_usuarios").val(detalles_piso.num_usuarios);
				datos["num_usuarios"] = detalles_piso.num_usuarios;

				$("#horario").val(detalles_piso.horario);
				datos["horario"] = detalles_piso.horario;

				$("#num_voluntarios").val(detalles_piso.num_voluntarios);
				datos["num_voluntarios"] = detalles_piso.num_voluntarios;


				datos["lavadora"] = detalles_piso.lavadora;
				if (detalles_piso.lavadora) {
					$("#lavadora").attr("src", "iconos/Lavadora.png");
				}
				datos["cocina"] = detalles_piso.cocina;
				if (detalles_piso.cocina == 1) {
					$("#cocina").attr("src", "iconos/Cocina.png");
				}
				datos["plancha"] = detalles_piso.plancha;
				if (detalles_piso.plancha == 1) {
					$("#plancha").attr("src", "iconos/Plancha.png");
				}
				datos["comida"] = detalles_piso.comida;
				if (detalles_piso.comida == 1) {
					$("#comida").attr("src", "iconos/Comida.png");
				}
				datos["ducha"] = detalles_piso.ducha;
				if (detalles_piso.ducha == 1) {
					$("#ducha").attr("src", "iconos/Ducha.png");
				}
				datos["movilidad"] = detalles_piso.movilidad;
				if (detalles_piso.movilidad == 1) {
					$("#movilidad").attr("src", "iconos/Movilidad.png");
				}
			}
		},
		error: function (response) {
			alert("Error inesperado");
			console.log(response);
		}
	});
});

function updateData() {
	console.log(datos);
	alert("Datos actualizados");
	/*$.ajax({
		type: "get",
		url: "../Server/modificaciones_vol.php",
		data: "datos:datos",
		dataType: "json",
		success: function (response) {
			alert("Datos actualizados");
		},
		error: function () {

		}
	});*/
}

function permitirModificarDatos() {
	$("button").removeClass("oculto");
	$("img").click(function (e) {
		e.preventDefault();
		var elemento = e.target;
		var imgSrc = elemento.getAttribute("src");
		var test = imgSrc.slice(imgSrc.indexOf('/') + 1);
		if (imgSrc.search("off") == -1) {
			datos[elemento.getAttribute("id")] = "0";
			var newSrc = test.slice(0, test.indexOf('.'));
			elemento.setAttribute("src", "Iconos/" + newSrc + "_off.png");
		} else {
			datos[elemento.getAttribute("id")] = "1";
			var newSrc = test.slice(0, test.indexOf('_'));
			elemento.setAttribute("src", "Iconos/" + newSrc + ".png");
		}
	});
}