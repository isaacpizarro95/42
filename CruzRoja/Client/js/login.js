function llamada() {
	var login = $("#login").val();
	var password = $("#password").val();
	if (login && password) {
		$.ajax({
			type: "post",
			url: "../Server/login.php",
			data: {
				"login": login,
				"password": password
			},
			dataType: "json",
			success: function (response) {
				if (typeof response.tipo !== "undefined") {
					window.localStorage.setItem('tipoUser', "" + response.tipo);
					location.href = "mapa_pisos.html";
				} else {
					if (response.error == -1) {
						alert("Necesitas rellenar los campos");
					} else {
						alert("Usuario o contraseña incorrectos");
					}
				}
			},
			error: function (response, xhttpError) {
				alert("Error inesperado");
			},
		});
	} else {
		alert("Rellena los campos");
	}
}