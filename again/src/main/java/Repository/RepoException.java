package Repository;

public class RepoException extends RuntimeException{
    public RepoException(){}

    public RepoException(String message){
        super(message);
    }
    public RepoException(Exception ex){super(ex);}
}
