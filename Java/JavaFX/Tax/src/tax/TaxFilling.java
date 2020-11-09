/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tax;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.text.Text;
import javafx.stage.Stage;



/**
 *
 * @author HP
 */
public class TaxFilling extends Application {
    double tax;
    Boolean taxCalculated=false;
    Text t2= new Text();
    int income;
    Text t6=new Text();
    @Override
    public void start(Stage primaryStage) {
        Text t1 = new Text("Income: ");
        TextField tf1 = new TextField();
        Button btn = new Button();
        
        Menu m = new Menu("Set Tax");
        MenuItem m1= new MenuItem("Tax Rate: 0%");
        m1.setUserData((double)0);
        MenuItem m2=new MenuItem("Tax Rate: 5%");
        m2.setUserData((double).05);
        MenuItem m3=new MenuItem("Tax Rate: 20%");
        m3.setUserData((double).2);
        MenuItem m4 = new MenuItem("Tax Rate: 30%");
        m4.setUserData((double).3);
        m.getItems().add(m1);
        m.getItems().add(m2);
        m.getItems().add(m3);
        m.getItems().add(m4);
        
        Button pay= new Button();
        pay.setText("Pay Tax");
        pay.setDisable(true);
        
        EventHandler<ActionEvent> event = new EventHandler<ActionEvent>() { 
            public void handle(ActionEvent e) 
            { 
                t2.setText(((MenuItem)e.getSource()).getText()); 
                tax=(double)((MenuItem)e.getSource()).getUserData();
                pay.setDisable(false);

            } 
        }; 
  
        // add event 
        m1.setOnAction(event); 
        m2.setOnAction(event); 
        m3.setOnAction(event); 
        
        m4.setOnAction(event);
  
        // create a menubar 
        MenuBar mb = new MenuBar(); 
  
        // add menu to menubar 
        mb.getMenus().add(m); 
        VBox vb=new VBox(mb);
        

        
        GridPane gridPane1 = new GridPane();    
        gridPane1.setAlignment(Pos.CENTER);
        gridPane1.add(t1,0,1);
        gridPane1.add(tf1, 1, 1);
        gridPane1.add(btn,1,2);
        gridPane1.add(t2,0,2);
        btn.setText("Calculate tax");
        
        
        
        btn.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) {
                
                int a = Integer.parseInt(tf1.getText());
                income = a;
                if(a<250000){
                    tax=0;
                }else if(a>=250000 && a<500000){
                    tax=.05;
                }else if(a>=500000 && a<1000000){
                    tax=.2;
                }else{
                    tax=.3;
                }
                System.out.println("Tax rate is:"+tax);
                t2.setText("Tax rate:"+(tax));
                pay.setDisable(false);

            }
        });
        
        //Tax Filling
        Text t3= new Text("Name:");
        Text t4 = new Text("Aadhar No:");
        Text t5 = new Text("Enter Amount:");
        
        TextField tf3 = new TextField();
        TextField tf4 = new TextField();
        TextField tf5 = new TextField();
        
        //GridPane gridPane2 = new GridPane();
        gridPane1.add(t3,0,3);
        gridPane1.add(tf3,1,3);
        gridPane1.add(t4,0,4);
        gridPane1.add(tf4,1,4);
        gridPane1.add(t5,0,5);
        gridPane1.add(tf5,1,5);
        gridPane1.add(t6,0,7);
        gridPane1.add(pay,1,6);
        
        pay.setOnAction(new EventHandler<ActionEvent>(){
            @Override
            public void handle(ActionEvent event) {
                if(tf5.getText()!=""){
                int amount = Integer.parseInt(tf5.getText());
                double rem=((double)amount-(income*tax));
                if(rem<0)rem=0;
                t6.setText("Balance in your account is:"+rem+"\nTax amount was:"+(income*tax));
            }}
        });
        
        StackPane root = new StackPane();
        root.getChildren().add(vb);
        root.getChildren().add(gridPane1);
        //root.getChildren().add(gridPane2);
        //root.getChildren().add(btn);
        
        
        Scene scene = new Scene(root, 400, 350);
        
        primaryStage.setTitle("Tax Filling System");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
