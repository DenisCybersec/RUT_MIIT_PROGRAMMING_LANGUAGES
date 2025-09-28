public final void getPersonalStatsFromFit(Context context, long startTime, long endTime,
        final Function1<? super ArrayList<StatisticMainModel>, Unit> onSuccessListener,
        final Function1<? super Throwable, Unit> onErrorListener) {

    Intrinsics.checkNotNullParameter(context, "context");
    Intrinsics.checkNotNullParameter(onSuccessListener, "onSuccessListener");
    Intrinsics.checkNotNullParameter(onErrorListener, "onErrorListener");

    try {
        long registrationDate = getRegistrationDate();
        long actualStart = startTime < registrationDate ? registrationDate : startTime;

        ArrayList<StatisticMainModel> statsList = new ArrayList<>();
        Calendar calendar = Calendar.getInstance();
        calendar.setTimeInMillis(actualStart);

        // normalize to midnight
        calendar.set(Calendar.HOUR_OF_DAY, 0);
        calendar.set(Calendar.MINUTE, 0);
        calendar.set(Calendar.SECOND, 0);

        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault());

        long constantSteps = 5000; // <-- your constant step count

        while (calendar.getTimeInMillis() <= endTime) {
            long dayStartMillis = calendar.getTimeInMillis();
            StatisticMainModel model = new StatisticMainModel(dayStartMillis);
            model.setLabel(sdf.format(new Date(dayStartMillis)));

            model.setSteps(constantSteps);

            int stepLength = getStepLengt();
            float distance = getDistance(constantSteps, stepLength);
            model.setDistance(distance);

            int calories = getCalories(constantSteps, distance);
            model.setCalories(calories);

            statsList.add(model);

            // move to next day
            calendar.add(Calendar.DAY_OF_MONTH, 1);
        }

        // call success listener
        onSuccessListener.invoke(statsList);

    } catch (Exception e) {
        // forward error
        onErrorListener.invoke(e);
        Log.i("PersonalStatisticsUtil", "getPersonalStatsFromFit ERROR: " + e);
    }
}

