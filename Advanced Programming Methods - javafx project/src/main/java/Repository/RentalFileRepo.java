package Repository;

import model.*;

import java.io.*;

public class RentalFileRepo extends RentalInMemoryRepo{
    private String filename;
    private CarRepo carRepo;
    private static int idGenerator=0;

    public RentalFileRepo(String filename,CarRepo carRepo) {
        this.filename = filename;
        this.carRepo=carRepo;
        readFromFile();
    }

    private void readFromFile(){
        try(BufferedReader br=new BufferedReader(new FileReader(filename))){
            String line=br.readLine();
            try{
                idGenerator=Integer.parseInt(line);
            }catch (NumberFormatException ex){
                System.err.println("Invalid Value for idGenerator, starting from 0");
            }
            while((line=br.readLine())!=null){
                String[] elems=line.split(";");
                if (elems.length!=5){
                    System.err.println("Invalid line ..."+line);
                    continue;
                }
                try {
                    int id = Integer.parseInt(elems[0]);
                    int days=Integer.parseInt(elems[3]);
                    int carID=Integer.parseInt(elems[4]);
                    //Car car=carRepo.findByID(carID);
                    Rental rental=new Rental(id,elems[1],elems[2],days,carID);
                    super.add(rental);

                }catch(NumberFormatException ex){
                    System.err.println("Invalid data "+ex);
                }catch (RepoException ex){
                    System.err.println("Repository Error "+ex);
                }
            }
        }catch (IOException ex){
            throw new RepoException("Error reading "+ex);
        }

    }

    @Override
    public Rental add(Rental el) {
        el.setID(getNextId());
        super.add(el);
        writeToFile();
        return el;
    }

    @Override
    public void delete(Rental el) {
        super.delete(el);
        writeToFile();
    }

    @Override
    public void update(Rental el, Integer integer) {
        super.update(el, integer);
        writeToFile();
    }

    private void writeToFile(){
        try(PrintWriter pw=new PrintWriter(filename)){
            pw.println(idGenerator);
            for(Rental rental:findAll()){
                pw.println(rental.getID()+";"+rental.getName()+";"+rental.getDate()+";"+rental.getNo_days()+";"+rental.getCarID());
            }
        }catch(IOException ex){
            throw new RepoException("Error writing "+ex);
        }

    }

    private static int getNextId(){
        return idGenerator++;
    }
}
