import 'package:flutter/material.dart';
import 'package:webview/webpagecustom.dart';
//import 'package:flutter_webview_plugin/flutter_webview_plugin.dart';
//import 'package:webview/webpagepm.dart';
import 'package:flutter/services.dart';

//import 'main.dart';
final _latitudeController = TextEditingController();
final _longitudeController = TextEditingController();

var lat45 = _latitudeController.text;
var lon45  = _longitudeController.text;
String lat = lat45;
String lon = lon45;

class Customloc extends StatefulWidget {
  @override
  _CustomlocState createState() => _CustomlocState();
}

class _CustomlocState extends State<Customloc> {


//  String lat =Text(_latitudeController.text );


  final _formKey = GlobalKey<FormState>();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Custom Location"),
      ),
      body: Form(
          key: _formKey,
          child: Column(
              crossAxisAlignment: CrossAxisAlignment.center,
              children: <Widget>[

                TextFormField(
                  controller: _latitudeController,
                  decoration: const InputDecoration(
                    hintText: 'Enter Latitude',
                    labelText: ' Latitude',
                  ),
                  keyboardType: TextInputType.number,
//                  inputFormatters: <TextInputFormatter>[
//                    WhitelistingTextInputFormatter.digitsOnly
//                  ],

                  validator: (value) {
                    if (value.isEmpty) {
                      return 'Please enter Latitude';
                    }
                    return null;
                  },
                ),

                TextFormField(
                  controller: _longitudeController,
                  decoration: const InputDecoration(
                    hintText: 'Enter Longitude',
                    labelText: ' Longitude',
                  ),
                  keyboardType: TextInputType.number,
//                  inputFormatters: <TextInputFormatter>[
//                    WhitelistingTextInputFormatter.digitsOnly
//                  ],
                  validator: (value) {
                    if (value.isEmpty) {
                      return 'Please enter Longitude';
                    }
                    return null;
                  },
                ),

                RaisedButton(
                  child: Text("WebView"),
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(builder: (context) => Webpagecm()),
                    );
                  },
                  color: Colors.blue,
                  textColor: Colors.white,
//                splashColor: Colors.grey,
                ),

              ]

          )
      ),
    );
  }
}
