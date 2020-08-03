import 'package:flutter/material.dart';

import 'package:flutter_webview_plugin/flutter_webview_plugin.dart';

import 'main.dart';

class con extends StatefulWidget {
  @override
  _conState createState() => _conState();
}

class _conState extends State<con> {
  @override
  Widget build(BuildContext context) {
    return WebviewScaffold(
      appBar: AppBar(
        title: Text(getlat +com+ getlon),
      ),


      url: "https://arpanofficial.000webhostapp.com/",
      withJavascript: true,
      withZoom: true,
      initialChild: Container(
        child: const Center(
          child: Text("Loading......"),

        ),
      ),
    );

  }
}
