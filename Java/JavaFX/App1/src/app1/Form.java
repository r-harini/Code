/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package app1;

import javafx.application.Application; 
import static javafx.application.Application.launch; 
import javafx.geometry.Insets; 
import javafx.geometry.Pos; 

import javafx.scene.Scene; 
import javafx.scene.control.Button; 
import javafx.scene.control.PasswordField; 
import javafx.scene.layout.GridPane; 
import javafx.scene.text.Text; 
import javafx.scene.control.TextField; 
import javafx.stage.Stage;  
import javafx.scene.layout.StackPane;

/**
 *
 * @author rhari
 */
public class Form extends Application{
    @Override
    public void start(Stage stage){
        
        Text text1=new Text("Surname");
        
        Text text2=new Text("Middle Name");
        
        Text text3= new Text("First name");
        
        StackPane root=new StackPane();
        root.getChildren().add(text1);
        
        Scene scene=new Scene(root,300,250);
        stage.setScene(scene);
        stage.show();
        
    }
    
}
